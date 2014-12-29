#include "ApplicationUI.hpp"
#include <bb/cascades/Application>
#include <QLocale>
#include <QTranslator>
#include <Qt/qdeclarativedebug.h>
#include <Flurry.h>

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    Flurry::Analytics::StartSession("MY5RTZ9MTFJKC838D3KR");

    Application app(argc, argv);
    ApplicationUI appui;
    return Application::exec();
}
