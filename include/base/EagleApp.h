#ifndef EAGLEAPP_H
#define EAGLEAPP_H

#include "MooseApp.h"

class EagleApp;

template<>
InputParameters validParams<EagleApp>();

class EagleApp : public MooseApp
{
public:
  EagleApp(InputParameters parameters);
  virtual ~EagleApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* EAGLEAPP_H */
