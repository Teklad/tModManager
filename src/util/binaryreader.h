#ifndef  _TMMUTIL_BINARYREADER_H_
#define  _TMMUTIL_BINARYREADER_H_

#include <stdint.h>
#include <string>
#include <vector>

namespace TMM {
/**
 * @brief Partial reimplementation of C#'s BinaryReader class in order to properly read tmod
 *        file data.
 */
class BinaryReader {
    public:
        BinaryReader(FILE *file);
        ~BinaryReader();
        void SkipBytes(int count);
        std::vector<uint8_t> ReadBytes(int count);
        void SetPosition(int count);
        long int GetPosition();
        std::string ReadString();
        uint8_t ReadByte();
        int ReadInt32();
    private:
        FILE *m_file = nullptr;
        int Read7BitEncodedInt();
};
}

#endif //_TMMUTIL_BINARYREADER_H_
