#pragma once
#include<memory>
#include "libavutil/timestamp.h"
#include "libavformat/avformat.h"
#include "libavutil/mathematics.h"

class Packet
{
public:
	Packet() = default;
	virtual ~Packet() = 0;
};
using PacketPtr = std::shared_ptr<Packet>();

class KiloviewPacket : public Packet {
public:
	KiloviewPacket() {

	}
	~KiloviewPacket() {
		if (packet) {
			av_packet_free(&packet);
		}
	}


	AVPacket* packet;
};
using KiloviewPacketPtr = std::shared_ptr<KiloviewPacket>();

class FFmpegPacket : public Packet {
public:
	FFmpegPacket() {

	}
	~FFmpegPacket() {
		if (packet) {
			av_packet_free(&packet);
		}
	}


	AVPacket* packet;
};
using FFmpegPacketPtr = std::shared_ptr<FFmpegPacket>();

