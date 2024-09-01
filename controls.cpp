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

    if (videoWidget->isFullScreen())
    {
        // If the videoWidget is already in fullscreen, restore it to normal size
        videoWidget->showNormal();
        ui->verticalLayout->addWidget(videoWidget); // Re-add to the layout if necessary
    }
    else
    {
        // Remove videoWidget from its current layout (if necessary)
        ui->verticalLayout->removeWidget(videoWidget);

        // Set the videoWidget to fullscreen mode
        videoWidget->setWindowFlag(Qt::Window); // Make it a top-level window
        videoWidget->showFullScreen();
    }
}

