#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "listmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Create and populate list model instance
    CListModel listModel;
    listModel.addData("Isaac Newton");
    listModel.addData("Alexander Graham Bell");
    listModel.addData("Leonhard Euler");
    listModel.addData("Nikola Tesla");
    listModel.addData("Charles-Augustin de Coulomb");
    listModel.addData("Andre-Marie Ampere");
    listModel.addData("Michael Faraday");
    listModel.addData("Blaise Pascal");
    listModel.addData("Anders Celsius");
    listModel.addData("James Watt");
//    listModel.addData("William Thomson, 1st Baron Kelvin");
//    listModel.addData("Alessandro Volta");
//    listModel.addData("Georg Simon Ohm");
//    listModel.addData("Joseph Henry");
//    listModel.addData("Wilhelm Eduard Weber");
//    listModel.addData("Ernst Werner von Siemens");
//    listModel.addData("James Prescott Joule");
//    listModel.addData("Antoine Henri Becquerel");
//    listModel.addData("Heinrich Rudolf Hertz");
//    listModel.addData("John Napier");
//    listModel.addData("Rolf Maximilian Sievert");
//    listModel.addData("Louis Harold Gray");

    //Create filter model
    FilterProxyModel filterModel;
    filterModel.setSourceModel(&listModel);
    filterModel.setFilterRole(NameRole);
    filterModel.setSortRole(NameRole);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("filterModel", &filterModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
