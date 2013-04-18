#include "cWebview.h"
#include "../manager.h"
#include "../main.h"

using namespace Controller;

const char* Webview::qCreateClient = "clients/new";
const char* Webview::qRegister = "signup";
const char* Webview::qDemo = "signup_email";

Webview::Webview(Manager::Webview* manager) : manager(manager)
{

}

Webview::~Webview()
{

}

void Webview::setHooks()
{
	//manager->view->setHardHook("http://.*");
}

MAUtil::String Webview::pageCreateClient()
{
	return MAUtil::String(Manager::main->host) + "/" + qCreateClient;
}

MAUtil::String Webview::pageRegister()
{
	return MAUtil::String(Manager::main->host) + "/" + qRegister;
}

void Webview::actionCreateClient()
{
	setHooks();

	const MAUtil::String& auth_token = Manager::main->mLogin.controller->getAuthToken();

	MAUtil::String request = pageCreateClient();

	if (auth_token.size())
		request += "?access_token=" + auth_token;

	manager->view->openURL(request);
	manager->view->show();
}

void Webview::actionRegister()
{
	setHooks();

	MAUtil::String request = pageRegister();

	manager->view->openURL(request);
	manager->view->show();
}
