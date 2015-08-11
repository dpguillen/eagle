#include "EagleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<EagleApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

EagleApp::EagleApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  EagleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  EagleApp::associateSyntax(_syntax, _action_factory);
}

EagleApp::~EagleApp()
{
}

// External entry point for dynamic application loading
extern "C" void EagleApp__registerApps() { EagleApp::registerApps(); }
void
EagleApp::registerApps()
{
  registerApp(EagleApp);
}

// External entry point for dynamic object registration
extern "C" void EagleApp__registerObjects(Factory & factory) { EagleApp::registerObjects(factory); }
void
EagleApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void EagleApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { EagleApp::associateSyntax(syntax, action_factory); }
void
EagleApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
