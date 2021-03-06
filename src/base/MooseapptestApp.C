#include "MooseapptestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"
#include "MyPostProc.h"

template<>
InputParameters validParams<MooseapptestApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MooseapptestApp::MooseapptestApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseapptestApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseapptestApp::associateSyntax(_syntax, _action_factory);
}

MooseapptestApp::~MooseapptestApp()
{
}

// External entry point for dynamic application loading
extern "C" void MooseapptestApp__registerApps() { MooseapptestApp::registerApps(); }
void
MooseapptestApp::registerApps()
{
  registerApp(MooseapptestApp);
}

// External entry point for dynamic object registration
extern "C" void MooseapptestApp__registerObjects(Factory & factory) { MooseapptestApp::registerObjects(factory); }
void
MooseapptestApp::registerObjects(Factory & factory)
{
  registerPostprocessor(MyPostProc);
}

// External entry point for dynamic syntax association
extern "C" void MooseapptestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MooseapptestApp::associateSyntax(syntax, action_factory); }
void
MooseapptestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
