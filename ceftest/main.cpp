#include "qtcef3.h"
#include <QtWidgets/QApplication>
#include "cefclient/cefclient_app.h"
#include "cefclient/cefview.h"
#include "include/base/cef_scoped_ptr.h"
#include "include/cef_command_line.h"
#include "include/cef_sandbox_win.h"
#include "cefclient/browser/client_app_browser.h"
#include "cefclient/browser/main_context_impl.h"
#include "cefclient/browser/main_message_loop_multithreaded_win.h"
#include "cefclient/browser/main_message_loop_std.h"
#include "cefclient/browser/root_window_manager.h"
#include "cefclient/browser/test_runner.h"
#include "cefclient/common/client_app_other.h"
#include "cefclient/common/client_switches.h"
#include "cefclient/renderer/client_app_renderer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HINSTANCE hInstance = ::GetModuleHandle(NULL);	
	CefEnableHighDPISupport();
	void* sandbox_info = NULL;

	CefMainArgs main_args(hInstance);
	/*CefRefPtr<cefclient_app> app(new cefclient_app());
	int exit_code = CefExecuteProcess(main_args, app.get(), sandbox_info);
	if (exit_code >= 0)
		return exit_code;
	CefSettings settings;
	settings.no_sandbox = true;
	settings.multi_threaded_message_loop = true;
	CefInitialize(main_args, settings, app.get(), sandbox_info);
*/


	// Parse command-line arguments.
	CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
	command_line->InitFromString(::GetCommandLineW());

	// Create a ClientApp of the correct type.
	CefRefPtr<CefApp> app;
	client::ClientApp::ProcessType process_type = client::ClientApp::GetProcessType(command_line);
	if (process_type == client::ClientApp::BrowserProcess)
		app = new client::ClientAppBrowser();
	else if (process_type == client::ClientApp::RendererProcess)
		app = new client::ClientAppRenderer();
	else if (process_type == client::ClientApp::OtherProcess)
		app = new client::ClientAppOther();

	// Execute the secondary process, if any.
	int exit_code = CefExecuteProcess(main_args, app, sandbox_info);
	if (exit_code >= 0)
		return exit_code;

	// Create the main context object.
	scoped_ptr<client::MainContextImpl> context(new client::MainContextImpl(command_line, true));

	CefSettings settings;

#if !defined(CEF_USE_SANDBOX)
	settings.no_sandbox = true;
#endif

	// Populate the settings based on command line arguments.
	context->PopulateSettings(&settings);

	// Create the main message loop object.
	scoped_ptr<client::MainMessageLoop> message_loop;
	if (settings.multi_threaded_message_loop)
		message_loop.reset(new client::MainMessageLoopMultithreadedWin);
	else
		message_loop.reset(new client::MainMessageLoopStd);

	// Initialize CEF.
	context->Initialize(main_args, settings, app, sandbox_info);

	
	// Run the message loop. This will block until Quit() is called by the
	// RootWindowManager after all windows have been destroyed.
	
	// Shut down CEF.
	




	qtcef3 w;
	w.resize(1500, 1000);
	w.CreateBrowser();
	w.show();
	if (!settings.multi_threaded_message_loop) {
		// Run the CEF message loop. This function will block until the application
		// recieves a WM_QUIT message.
		int result = message_loop->Run();

	}
	else {
			exit_code = a.exec();
	}
	message_loop->Quit();
	context->Shutdown();

	// Release objects in reverse order of creation.
	message_loop.reset();
	context.reset();
	return exit_code;
}
