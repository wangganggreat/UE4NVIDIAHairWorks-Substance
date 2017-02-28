// Copyright (c) 2016 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/browser_process_handler_cpptoc.h"
#include "libcef_dll/cpptoc/print_handler_cpptoc.h"
#include "libcef_dll/ctocpp/command_line_ctocpp.h"
#include "libcef_dll/ctocpp/list_value_ctocpp.h"


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK browser_process_handler_on_context_initialized(
    struct _cef_browser_process_handler_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefBrowserProcessHandlerCppToC::Get(self)->OnContextInitialized();
}

void CEF_CALLBACK browser_process_handler_on_before_child_process_launch(
    struct _cef_browser_process_handler_t* self,
    struct _cef_command_line_t* command_line) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: command_line; type: refptr_diff
  DCHECK(command_line);
  if (!command_line)
    return;

  // Execute
  CefBrowserProcessHandlerCppToC::Get(self)->OnBeforeChildProcessLaunch(
      CefCommandLineCToCpp::Wrap(command_line));
}

void CEF_CALLBACK browser_process_handler_on_render_process_thread_created(
    struct _cef_browser_process_handler_t* self,
    struct _cef_list_value_t* extra_info) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: extra_info; type: refptr_diff
  DCHECK(extra_info);
  if (!extra_info)
    return;

  // Execute
  CefBrowserProcessHandlerCppToC::Get(self)->OnRenderProcessThreadCreated(
      CefListValueCToCpp::Wrap(extra_info));
}

struct _cef_print_handler_t* CEF_CALLBACK browser_process_handler_get_print_handler(
    struct _cef_browser_process_handler_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefPrintHandler> _retval = CefBrowserProcessHandlerCppToC::Get(
      self)->GetPrintHandler();

  // Return type: refptr_same
  return CefPrintHandlerCppToC::Wrap(_retval);
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefBrowserProcessHandlerCppToC::CefBrowserProcessHandlerCppToC() {
  GetStruct()->on_context_initialized =
      browser_process_handler_on_context_initialized;
  GetStruct()->on_before_child_process_launch =
      browser_process_handler_on_before_child_process_launch;
  GetStruct()->on_render_process_thread_created =
      browser_process_handler_on_render_process_thread_created;
  GetStruct()->get_print_handler = browser_process_handler_get_print_handler;
}

template<> CefRefPtr<CefBrowserProcessHandler> CefCppToC<CefBrowserProcessHandlerCppToC,
    CefBrowserProcessHandler, cef_browser_process_handler_t>::UnwrapDerived(
    CefWrapperType type, cef_browser_process_handler_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefBrowserProcessHandlerCppToC,
    CefBrowserProcessHandler, cef_browser_process_handler_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefBrowserProcessHandlerCppToC,
    CefBrowserProcessHandler, cef_browser_process_handler_t>::kWrapperType =
    WT_BROWSER_PROCESS_HANDLER;
