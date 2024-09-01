#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QVideoWidget>
#include <QVideoSink>
#include <QAudioOutput>
#include <QToolButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QString>
#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QListWidget>
#include <QWidget>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>
#include "ui_mainwindow.h"

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/avutil.h>
    #include <libavutil/log.h>
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString statusMessage, stateMessage, title, artist;
    std::vector<std::map<QString, QString>> metadataMap;
    std::map<QString, QString> array;
    void populateFileList();
    void GetMetadata(const char* mediaFile);

private slots:
    void MediaStatus(QMediaPlayer::MediaStatus status); // Get Media Status
    void StateChanged(QMediaPlayer::PlaybackState state);
    void Selected(QListWidgetItem *item); // Slot to handle item click
    void Quit();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QVideoWidget *videoWidget;
    void updateStatusBar();
    void Play();
    void Stop();
    void FullScreen();

};

#endif // MAINWINDOW_H
