//
// Created by Xana Hopper on 2021/4/24.
//

#pragma once

#include "platform/CanvasRenderingContext2D.h"

#include "math/Math.h"
#include "platform/android/jni/JniHelper.h"
#include "platform/android/jni/JniImp.h"


#ifndef JCLS_CANVASIMPL
#define JCLS_CANVASIMPL "com/cocos/lib/CanvasRenderingContext2DImpl"
#endif

enum class CanvasTextAlign {
    LEFT,
    CENTER,
    RIGHT
};

enum class CanvasTextBaseline {
    TOP,
    MIDDLE,
    BOTTOM,
    ALPHABETIC
};

class CanvasRenderingContext2DImpl {
public:
    CanvasRenderingContext2DImpl();

    ~CanvasRenderingContext2DImpl();

    void recreateBuffer(float w, float h);

    void beginPath();

    void closePath();

    void moveTo(float x, float y);

    void lineTo(float x, float y);

    void stroke();

    void fill();

    void saveContext();

    void restoreContext();

    void rect(float x, float y, float w, float h);

    void clearRect(float x, float y, float w, float h);

    void fillRect(float x, float y, float w, float h);

    void fillText(const std::string &text, float x, float y, float maxWidth);

    void strokeText(const std::string &text, float x, float y, float maxWidth);

    float measureText(const std::string &text);

    void updateFont(const std::string &fontName, float fontSize, bool bold, bool italic, bool oblique, bool smallCaps);

    void setLineCap(const std::string &lineCap);

    void setLineJoin(const std::string &lineJoin);

    void setTextAlign(CanvasTextAlign align);

    void setTextBaseline(CanvasTextBaseline baseline);

    void setFillStyle(float r, float g, float b, float a);

    void setStrokeStyle(float r, float g, float b, float a);

    void setLineWidth(float lineWidth);

    void _fillImageData(const cc::Data &imageData, float imageWidth, float imageHeight, float offsetX, float offsetY);

    const cc::Data &getDataRef() const;

    void unMultiplyAlpha(unsigned char *ptr, ssize_t size);

    void fillData();

private:
    jobject _obj = nullptr;
    cc::Data _data;
    float _bufferWidth = 0.0f;
    float _bufferHeight = 0.0f;
};
