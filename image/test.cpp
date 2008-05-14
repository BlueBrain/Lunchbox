
/* Copyright (c) 2006-2007, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#include <test.h>

#include <eq/base/clock.h>
#include <eq/client/image.h>

using namespace eqBase;
using namespace eq;
using namespace std;

// Tests the functionality of the compressor and computes the bandwidth
// threshold upon which the compression is slower than sending uncompressed
// data.

int main( int argc, char **argv )
{
    Image image;
    TEST( image.readImage( "../compositor/Image_1_color.rgb",
                           Frame::BUFFER_COLOR ));

    Image destImage;
    destImage.setPixelViewport( image.getPixelViewport( ));

    const uint8_t* colorData = image.getPixelData( Frame::BUFFER_COLOR );
    const size_t   colorSize = image.getPixelDataSize( Frame::BUFFER_COLOR );
    const uint8_t* compressedData;
    const uint8_t* data;
    uint32_t       size;
    uint32_t       resultSize;
    Clock          clock;
    float          time;

    // Color
    clock.reset();
    compressedData = image.compressPixelData( Frame::BUFFER_COLOR, size );
    time = clock.getTimef();

    cout << argv[0] << ": Color " << colorSize << "->" << size << " " 
         << 100.0f * size / colorSize << "%, " << time << " ms ("
         << 1000.0f * colorSize / time / 1024.0f / 1024.0f 
         << " MB/s), max network bw " 
         << 1000.0f * (colorSize - size) / time / 1024.0f / 1024.0f << "MB/s" 
         << endl;

    clock.reset();
    resultSize = destImage.decompressPixelData( Frame::BUFFER_COLOR, 
                                                compressedData );
    TESTINFO( size == resultSize, size << " == " << resultSize );
          
    time = clock.getTimef();

    cout << argv[0] << ": Color " << size  << "->" << colorSize << " " << time
         << " ms, max bw " 
         << 1000.0f * (colorSize - size) / time / 1024.0f / 1024.0f << "MB/s" 
         << endl;

    data = destImage.getPixelData( Frame::BUFFER_COLOR );
    for( uint32_t i=0; i<colorSize-7; ++i ) // last 7 pixels can be unitialized
        TEST( colorData[i] == data[i] );


    // Depth
    TEST( image.readImage( "../compositor/Image_1_depth.rgb",
                           Frame::BUFFER_DEPTH ));
    const uint8_t* depthData = image.getPixelData( Frame::BUFFER_DEPTH);
    const size_t   depthSize = image.getPixelDataSize( Frame::BUFFER_DEPTH);

    destImage.setPixelViewport( image.getPixelViewport( ));

    clock.reset();
    compressedData = image.compressPixelData( Frame::BUFFER_DEPTH, size );
    time = clock.getTimef();

    cout << argv[0] << ": Depth " << depthSize << "->" << size << " " 
         << 100.0f * size / depthSize << "%, " << time << " ms ("
         << 1000.0f * depthSize / time / 1024.0f / 1024.0f 
         << " MB/s), max network bw " 
         << 1000.0f * (depthSize - size) / time / 1024.0f / 1024.0f << "MB/s" 
         << endl;

    clock.reset();
    resultSize = destImage.decompressPixelData( Frame::BUFFER_DEPTH, 
                                                compressedData );
    TESTINFO( size == resultSize, size << " == " << resultSize );
    time = clock.getTimef();

    cout << argv[0] << ": Depth " << size  << "->" << depthSize << " " << time
         << " ms, max bw " 
         << 1000.0f * (depthSize - size) / time / 1024.0f / 1024.0f << "MB/s" 
         << endl;

    data = destImage.getPixelData( Frame::BUFFER_DEPTH );
    for( uint32_t i=0; i<depthSize-7; ++i ) // last 7 pixels can be unitialized
        TEST( depthData[i] == data[i] );
}
