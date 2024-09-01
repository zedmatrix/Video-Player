void MainWindow::Play () {
    if (player->isPlaying()) {

        player->pause();

    } else {
        audioOutput->setVolume(0.3); // Volume is from 0.0 to 1.0
        player->setVideoOutput(videoWidget);
        player->setAudioOutput(audioOutput);
        player->play();

    }
}

void MainWindow::Stop () {
    if (player->isPlaying()) {
        player->stop();
    }
}

void MainWindow::Quit () {
    QCoreApplication::quit();
}

void MainWindow::FullScreen () {
    ui->rawText->append("Full Screen");
    QDialog *fullScreenDialog = nullptr;

    // Check if the fullscreen dialog already exists
    if (!fullScreenDialog)
    {
        fullScreenDialog = new QDialog(this);
        fullScreenDialog->setWindowFlag(Qt::FramelessWindowHint); // Remove window borders
        fullScreenDialog->setWindowFlag(Qt::Window); // Set as a top-level window
        fullScreenDialog->setModal(true); // Modal dialog
        fullScreenDialog->setWindowTitle("Fullscreen Video");

        QVBoxLayout *dialogLayout = new QVBoxLayout(fullScreenDialog);
        fullScreenDialog->setLayout(dialogLayout);

        // Remove the videoWidget from its current layout
        ui->verticalLayout->removeWidget(videoWidget);

        // Add the videoWidget to the dialog layout
        dialogLayout->addWidget(videoWidget);
        // Connect the QDialog rejected signal to restore the videoWidget to MainWindow
        connect(fullScreenDialog, &QDialog::rejected, this, &MainWindow::restoreVideoWidget);

        // Resize and show the dialog in fullscreen
        fullScreenDialog->showFullScreen();
    } else {
        // If already fullscreen, restore to original layout
        ui->verticalLayout->addWidget(videoWidget);
        fullScreenDialog->hide();
        delete fullScreenDialog;
        fullScreenDialog = nullptr;
    }
}
void MainWindow::restoreVideoWidget()
{
    // Restore the videoWidget to the MainWindow layout
    ui->verticalLayout->addWidget(videoWidget);

    // Hide and delete the fullscreen dialog
    fullScreenDialog->hide();
    delete fullScreenDialog;
    fullScreenDialog = nullptr;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Ensure that videoWidget is returned to the MainWindow before closing
    if (fullScreenDialog)
    {
        ui->verticalLayout->addWidget(videoWidget);
        fullScreenDialog->hide();
        delete fullScreenDialog;
        fullScreenDialog = nullptr;
    }
    QMainWindow::closeEvent(event);
}
