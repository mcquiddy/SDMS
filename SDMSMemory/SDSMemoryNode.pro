#-------------------------------------------------
#
# Project created by QtCreator 2015-09-03T05:24:27
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SDSMemoryNode
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sdsmemorynode.cpp \
    memorymannager.cpp \
    d_pointer_size_type.cpp \
    darray.cpp \
    dchar.cpp \
    dint.cpp \
    dlong.cpp \
    dobject.cpp \
    sdsmemoryserver.cpp \
    socketserver.cpp

HEADERS += \
    sdsmemorynode.h \
    linked_list.h \
    Node.h \
    constants_SDSM.h \
    memorymannager.h \
    rapidjson/error/en.h \
    rapidjson/error/error.h \
    rapidjson/internal/biginteger.h \
    rapidjson/internal/diyfp.h \
    rapidjson/internal/dtoa.h \
    rapidjson/internal/ieee754.h \
    rapidjson/internal/itoa.h \
    rapidjson/internal/meta.h \
    rapidjson/internal/pow10.h \
    rapidjson/internal/stack.h \
    rapidjson/internal/strfunc.h \
    rapidjson/internal/strtod.h \
    rapidjson/internal/swap.h \
    rapidjson/msinttypes/inttypes.h \
    rapidjson/msinttypes/stdint.h \
    rapidjson/allocators.h \
    rapidjson/document.h \
    rapidjson/encodedstream.h \
    rapidjson/encodings.h \
    rapidjson/filereadstream.h \
    rapidjson/filewritestream.h \
    rapidjson/memorybuffer.h \
    rapidjson/memorystream.h \
    rapidjson/pointer.h \
    rapidjson/prettywriter.h \
    rapidjson/rapidjson.h \
    rapidjson/reader.h \
    rapidjson/stringbuffer.h \
    rapidjson/writer.h \
    d_pointer_size_type.h \
    darray.h \
    dchar.h \
    dint.h \
    dlong.h \
    dobject.h \
    sdsmemoryserver.h \
    socketserver.h
