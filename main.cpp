#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto widget = new QWidget;
    auto layout = new QVBoxLayout(widget);

    auto button = new QPushButton("Check", nullptr);
    auto text = new QTextEdit("", widget);

    layout->addWidget(text);
    layout->addWidget(button);

    widget->setLayout(layout);
    widget->show();

    return QApplication::exec();
}
