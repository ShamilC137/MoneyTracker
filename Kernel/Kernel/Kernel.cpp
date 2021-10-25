#include "Kernel.hpp"

namespace kernel {
// NOTE: function marked as "Parallel" can be called from few threads
// and must not block other such functions, but block other call of themselfs

// Ctors
Kernel::Kernel() noexcept(false) : mmu_(kMMUSize) /*throws std::bad_alloc*/ {}

// FIXME: Multithreading
[[nodiscard]] void *Kernel::Allocate(const std::size_t align,
                                     const std::size_t nbytes) noexcept(false) {
  return mmu_.Allocate(align, nbytes); // throws: std::bad_alloc
}

// FIXME: Multithreading
void Kernel::Deallocate(void *ptr, const size_t nbytes) noexcept {
  mmu_.Deallocate(ptr, nbytes);
}

// FIXME: stub
void Kernel::AddModule(impl::AbstractModule * /*module*/) {}

// FIXME: stub
[[nodiscard]] int Kernel::Run() { return {}; }
} // namespace kernel

namespace api {
namespace kernel_api {
kernel::Kernel &GetKernel() noexcept {
  static kernel::Kernel kernel{};
  return kernel;
}

[[nodiscard]] void *Allocate(const std::size_t align,
                             const std::size_t nbytes) noexcept(false) {
  return GetKernel().Allocate(align, nbytes); // throws: std::bad_alloc
}

void Deallocate(void *ptr, const std::size_t nbytes) noexcept {
  GetKernel().Deallocate(ptr, nbytes);
}

void PushToKernelQueue(const api::TaskWrapper &task) {
  GetKernel().PushToQueue(task);
}

void AddModule(impl::AbstractModule *module) { GetKernel().AddModule(module); }

[[nodiscard]] int Run() { return GetKernel().Run(); }
} // namespace kernel_api
} // namespace api
