
# Copyright (c) 2012-2013 Stefan Eilemann <eile@eyescale.ch>

set(LUNCHBOX_PUBLIC_HEADERS
  ${OUTPUT_INCLUDE_DIR}/lunchbox/version.h
  ${DEFINES_FILE}
  algorithm.h
  any.h
  anySerialization.h
  api.h
  atomic.h
  bitOperation.h
  buffer.h
  clock.h
  compiler.h
  compressor.h
  condition.h
  daemon.h
  debug.h
  decompressor.h
  defines.h
  downloader.h
  dso.h
  file.h
  future.h
  hash.h
  indexIterator.h
  init.h
  launcher.h
  lfQueue.h
  lfVector.h
  lfVector.ipp
  lfVectorIterator.h
  lock.h
  lockable.h
  log.h
  lunchbox.h
  memoryMap.h
  monitor.h
  mtQueue.h
  mtQueue.ipp
  nonCopyable.h
  omp.h
  os.h
  perThread.h
  perThreadRef.h
  plugin.h
  pluginRegistry.h
  pluginVisitor.h
  pool.h
  refPtr.h
  referenced.h
  requestHandler.h
  rng.h
  scopedMutex.h
  serializable.h
  servus.h
  sleep.h
  spinLock.h
  stdExt.h
  thread.h
  threadID.h
  timedLock.h
  tls.h
  types.h
  uint128_t.h
  unorderedIntervalSet.h
  unorderedIntervalSet.ipp
  uploader.h
  uuid.h
  visitorResult.h
  )

set(LUNCHBOX_SOURCES
  any.cpp
  atomic.cpp
  clock.cpp
  compressor.cpp
  compressorInfo.h
  condition.cpp
  condition_w32.ipp
  debug.cpp
  decompressor.cpp
  downloader.cpp
  dso.cpp
  file.cpp
  init.cpp
  launcher.cpp
  lock.cpp
  log.cpp
  memoryMap.cpp
  omp.cpp
  plugin.cpp
  pluginInstance.h
  pluginRegistry.cpp
  referenced.cpp
  requestHandler.cpp
  rng.cpp
  servus.cpp
  sleep.cpp
  spinLock.cpp
  thread.cpp
  threadID.cpp
  tls.cpp
  timedLock.cpp
  uint128_t.cpp
  uploader.cpp
  uuid.cpp
  version.cpp
  md5/md5.cc
  )

set(PLUGIN_HEADERS
  plugins/compressor.h
  plugins/compressorTokens.h
  plugins/compressorTypes.h
  )

set(LUNCHBOX_COMPRESSORS
  compressor/compressor.cpp
  compressor/compressor.h
  compressor/compressorFastLZ.cpp
  compressor/compressorFastLZ.h
  compressor/compressorLZF.cpp
  compressor/compressorLZF.h
  compressor/compressorRLE.ipp
  compressor/compressorRLE10A2.cpp
  compressor/compressorRLE10A2.h
  compressor/compressorRLE4B.cpp
  compressor/compressorRLE4B.h
  compressor/compressorRLE4BU.cpp
  compressor/compressorRLE4BU.h
  compressor/compressorRLE4HF.cpp
  compressor/compressorRLE4HF.h
  compressor/compressorRLE565.cpp
  compressor/compressorRLE565.h
  compressor/compressorRLEB.cpp
  compressor/compressorRLEB.h
  compressor/compressorRLEYUV.cpp
  compressor/compressorRLEYUV.h
  compressor/compressorSnappy.cpp
  compressor/compressorSnappy.h
  compressor/fastlz/fastlz.c
  compressor/fastlz/fastlz.h
  compressor/liblzf/lzf.h
  compressor/liblzf/lzf_c.c
  compressor/liblzf/lzf_d.c
  compressor/snappy/snappy.h
  compressor/snappy/snappy.cc
  compressor/snappy/snappy-sinksource.cc
  )

if(LibJpegTurbo_FOUND)
  list(APPEND LUNCHBOX_LINKLIBS ${LibJpegTurbo_LIBRARIES})
  list(APPEND LUNCHBOX_COMPRESSORS
    compressor/compressorTurboJPEG.h compressor/compressorTurboJPEG.cpp)
endif()

set(LUNCHBOX_ALL ${LUNCHBOX_PUBLIC_HEADERS} ${LUNCHBOX_SOURCES}
  ${PLUGIN_HEADERS} ${LUNCHBOX_COMPRESSORS})
list(SORT LUNCHBOX_ALL)
