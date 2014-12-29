#include <bb/Application>
#include "Service.hpp"
#include <QLocale>
#include <QTranslator>

using namespace bb;

int main(int argc, char **argv)
{
    Application app(argc, argv);
    Service srv;
    return Application::exec();
}
