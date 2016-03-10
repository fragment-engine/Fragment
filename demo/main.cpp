#include <Fragment/Script/ScriptEngine.h>

using Fragment::Script::ScriptEngine;

int main(int argc, char* argv[]) {
   ScriptEngine sc;

   return sc.Init(argc, argv);
}