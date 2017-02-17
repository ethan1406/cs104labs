#include <QString>
#include <QFont>
#include "post_widget.h"

PostWidget::PostWidget(Post* p) {
	post = p;
	layout = new QGridLayout();

	// ADD YOUR CODE HERE.
	// Create the suitable labels and add them to GridLayout properly.
	titleLabel = new QLabel(QString::fromStdString(p->title));
	usernameLabel = new QLabel(QString::fromStdString(p->username));
	subredditLabel = new QLabel(QString::fromStdString(p->subreddit));
	urlLabel = new QLabel(QString::fromStdString(p->url));
	karmaLabel = new QLabel(QString::number(p->karma));

	layout->addWidget(titleLabel, 0, 4, 1, 5);
	layout->addWidget(usernameLabel, 1, 4, 1, 5);
	layout->addWidget(subredditLabel, 2, 4, 1, 5);
	layout->addWidget(urlLabel, 3, 4, 1, 5);
	layout->addWidget(karmaLabel, 0, 0, 4, 3);
	setLayout(layout);

}

PostWidget::~PostWidget() {
	delete titleLabel;
	delete usernameLabel;
	delete subredditLabel;
	delete urlLabel;
	delete karmaLabel;
	delete layout;
}
