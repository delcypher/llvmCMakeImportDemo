#include "llvmCMakeImportDemo/Foo.h"
#include "llvmCMakeImportDemo/Config.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
namespace llvmCMakeImportDemo {
void Foo::sayHello() {
  outs() << "Hello there. We are using LLVM " << LLVM_PACKAGE_VERSION << "\n";
}
}
