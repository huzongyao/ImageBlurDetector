package com.hzy.blur.detect.demo;

import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.blankj.utilcode.util.ImageUtils;
import com.hzy.blur.detect.demo.utils.ActionUtils;
import com.hzy.blur.detector.BlurDetectorApi;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity {

    private TextView mTextLevel;
    private ImageView mImageSelect;
    private Bitmap mDemoBitmap;
    private ExecutorService mExecutorService;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextLevel = findViewById(R.id.text_level);
        mImageSelect = findViewById(R.id.image_select);
        mExecutorService = Executors.newSingleThreadExecutor();
        mImageSelect.setOnClickListener((v) ->
                ActionUtils.startImageContentAction(this, 103));
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (requestCode == 103) {
            if (resultCode == RESULT_OK) {
                if (data != null) {
                    Bitmap bitmap = ActionUtils.getBmpFromIntent(data);
                    if (bitmap != null) {
                        if (mDemoBitmap != null) {
                            mDemoBitmap.recycle();
                        }
                        bitmap = ImageUtils.compressBySampleSize(bitmap,
                                1600, 1600, true);
                        mDemoBitmap = bitmap.copy(Bitmap.Config.ARGB_8888, true);
                        bitmap.recycle();
                        mImageSelect.setImageBitmap(mDemoBitmap);
                        detectFromBitmap();
                    }
                }
            }
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    private void detectFromBitmap() {
        mExecutorService.submit(() -> {
            double result = BlurDetectorApi.detectFromBmp(mDemoBitmap);
            runOnUiThread(() -> {
                mImageSelect.setImageBitmap(mDemoBitmap);
                mTextLevel.setText(getString(R.string.level_format, result));
            });
        });
    }
}
