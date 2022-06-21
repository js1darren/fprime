// ======================================================================
// \title  DeframingTester.hpp
// \author bocchino
// \brief  hpp file for DeframingTester class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/SerialBuffer.hpp"
#include "Svc/FramingProtocol/FprimeProtocol.hpp"
#include "Svc/FramingProtocol/DeframingProtocol.hpp"
#include "Utils/Hash/Hash.hpp"
#include "Utils/Types/CircularBuffer.hpp"

namespace Svc {

  //! A harness for checking deframing
  class DeframingTester {

    private:

      // ----------------------------------------------------------------------
      // Constants and types
      // ----------------------------------------------------------------------

#if 0
      //! The serialized packet type
      typedef I32 SerialPacketType;
#endif

      //! Constants
      enum Constants {
        //! The maximum buffer size
        MAX_BUFFER_SIZE = 1024,
#if 0
        //! The maximum allowed data size
        MAX_DATA_SIZE = MAX_BUFFER_SIZE -
          sizeof FpFrameHeader::START_WORD -
          sizeof(SerialPacketType) -
          HASH_DIGEST_LENGTH,
        //! The offset of the start word in an F Prime protocol frame
        START_WORD_OFFSET = 0,
        //! The offset of the packet size in an F Prime protocol frame
        PACKET_SIZE_OFFSET = START_WORD_OFFSET +
            sizeof FpFrameHeader::START_WORD,
        //! The offset of the packet type in an F Prime protocol frame
        PACKET_TYPE_OFFSET = FpFrameHeader::SIZE,
#endif
      };

      //! The deframing protocol interface
      class Interface :
        public DeframingProtocolInterface
      {

        public:

          //! Construct an Interface
          Interface(
              DeframingTester& deframingTester //!< The enclosing DeframingTester
          ) :
            deframingTester(deframingTester),
            routedBuffer(nullptr)
          {

          }

        public:

          //! Allocate the buffer
          Fw::Buffer allocate(const U32 size) {
            FW_ASSERT(size <= MAX_BUFFER_SIZE);
            Fw::Buffer buffer(this->deframingTester.bufferStorage, size);
            return buffer;
          }

          //! Route the buffer
          void route(Fw::Buffer& data) {
            this->routedBuffer = &data;
          }

          //! Get the routed buffer
          Fw::Buffer *getRoutedBuffer() {
            return this->routedBuffer;
          }

        private:

          //! The enclosing DeframingTester
          DeframingTester& deframingTester;

          //! The routed buffer
          Fw::Buffer *routedBuffer;

      };

#if 0
    public:

      // ----------------------------------------------------------------------
      // Construction
      // ----------------------------------------------------------------------

      //! Construct a DeframingTester
      DeframingTester(
          Fw::ComPacket::ComPacketType packetType //!< The packet type
      );
#endif

#if 0
    public:

      // ----------------------------------------------------------------------
      // Public member functions
      // ----------------------------------------------------------------------

      //! Check framing
      void check();
#endif

#if 0
      // ----------------------------------------------------------------------
      // Private member functions
      // ----------------------------------------------------------------------

    private:

      //! Get the packet size from the buffer
      FpFrameHeader::TokenType getPacketSize();

      //! Check the packet size in the buffer
      void checkPacketSize(
          FpFrameHeader::TokenType packetSize //!< The packet size
      );

      //! Check the packet type in the buffer
      void checkPacketType();

      //! Check the start word in the buffer
      void checkStartWord();

      //! Check the data in the buffer
      void checkData();

      //! Check the hash value in the buffer
      void checkHash(
          FpFrameHeader::TokenType packetSize //!< The packet size
      );
#endif

    private:

      // ----------------------------------------------------------------------
      // Private member variables
      // ----------------------------------------------------------------------

#if 0
      //! The data to frame
      U8 data[MAX_DATA_SIZE];

      //! The data size in bytes
      const U32 dataSize;

      //! The packet type
      Fw::ComPacket::ComPacketType packetType;
#endif

      //! Storage for the buffer
      U8 bufferStorage[MAX_BUFFER_SIZE];

      //! The framing protocol interface
      Interface interface;

      //! The F Prime framing protocol
      FprimeDeframing fprimeDeframing;

  };

}
