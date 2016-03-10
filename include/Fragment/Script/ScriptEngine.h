//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_SCRIPTENGINE_H
#define FRAGMENT_SCRIPTENGINE_H

#include <include/v8.h>
#include <include/libplatform/libplatform.h>

namespace Fragment {
    namespace Script {

        class ScriptEngine {
        public:
            ScriptEngine();

            int Init(int argc, char* argv[]);

            class ShellArrayBufferAllocator;

            static v8::Local<v8::Context> CreateShellContext(v8::Isolate *isolate);

            static void RunShell(v8::Local<v8::Context> context, v8::Platform *platform);

            static int RunMain(v8::Isolate *isolate, v8::Platform *platform, int argc,
                        char *argv[]);

            static bool ExecuteString(v8::Isolate *isolate, v8::Local<v8::String> source,
                               v8::Local<v8::Value> name, bool print_result,
                               bool report_exceptions);

            static void Print(const v8::FunctionCallbackInfo<v8::Value> &args);

            static void Read(const v8::FunctionCallbackInfo<v8::Value> &args);

            static void Load(const v8::FunctionCallbackInfo<v8::Value> &args);

            static void Quit(const v8::FunctionCallbackInfo<v8::Value> &args);

            static void Version(const v8::FunctionCallbackInfo<v8::Value> &args);

            static v8::MaybeLocal<v8::String> ReadFile(v8::Isolate *isolate, const char *name);

            static void ReportException(v8::Isolate *isolate, v8::TryCatch *handler);

            static bool run_shell;

        };

    }
}

#endif //FRAGMENT_SCRIPTENGINE_H
