#include "llvmCMakeImportDemo/Foo.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvmCMakeImportDemo;

int main(int argc, char** argv) {
  llvm::outs() << "Hello World\n";

  Foo fooObj;

  fooObj.sayHello();
  return 0;
}
