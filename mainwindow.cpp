#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.cpp"
#include "controls.cpp"
#include "populateFilelist.cpp"
#include "getMetadata.cpp"
#include "MediaStatus.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)                        // Call the base class constructor
    , ui(new Ui::MainWindow)                     // Initialize the Ui pointer
    , player(new QMediaPlayer(this))             // Initialize the QMediaPlayer with 'this' as the parent
    , videoWidget(new QVideoWidget(this))        // Initialize the QVideoWidget with 'this' as the parent
    , audioOutput(new QAudioOutput(this))        // Initialize the QAudioOutput with 'this' as the parent
{
    // Setup the Ui:: MainWindow
    ui->setupUi(this);
    ui->verticalLayout->addWidget(videoWidget);

    av_log_set_level(AV_LOG_QUIET);
    avformat_network_init();

    // Setup External Variables from "global.cpp"
    this->setWindowTitle(App_Name + " " + App_Version);
    populateFileList();

    // connect the buttons to routines
    connect(ui->Quit, &QPushButton::clicked, this, &MainWindow::Quit);
    connect(ui->Play, &QPushButton::clicked, this, &MainWindow::Play);
    connect(ui->Stop, &QPushButton::clicked, this, &MainWindow::Stop);
    connect(ui->FullScreen, &QPushButton::clicked, this, &MainWindow::FullScreen);
    connect(ui->fileList, &QListWidget::itemClicked, this, &MainWindow::Selected);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::MediaStatus);
    connect(player, &QMediaPlayer::playbackStateChanged, this, &MainWindow::StateChanged);

}

MainWindow::~MainWindow()
{
    // Stop the media player if it's playing
    if (player->isPlaying()) {
        player->stop();
    }

    // Delete the media player
    avformat_network_deinit();
    delete player;
    delete ui;
}

