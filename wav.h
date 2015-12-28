#ifndef CTT_WAV_H_
#define CTT_WAV_H_

#include "stream.h"
#include <memory>

namespace wav {

struct Info {
  bool stereo;
  unsigned sample_rate;
  unsigned bits_per_sample;
};

struct IInputWavStream : public IInputStream {
  virtual Info GetInfo() const = 0;
};

using InputWavStreamPtr = std::unique_ptr<IInputWavStream>;
InputWavStreamPtr ReadWavFile(const std::string& fname);

}  // namespace wav

#endif  // CTT_WAV_H_
