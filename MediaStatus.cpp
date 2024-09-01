void MainWindow::updateStatusBar() {
    ui->statusbar->showMessage(stateMessage + " | " + statusMessage);
}

void MainWindow::StateChanged(QMediaPlayer::PlaybackState state) {
    switch (state) {
        case QMediaPlayer::PlayingState:
            stateMessage = "Media is playing";
            // Additional logic for when media is playing
            break;
        case QMediaPlayer::PausedState:
            stateMessage = "Media is paused";
            // Additional logic for when media is paused
            break;
        case QMediaPlayer::StoppedState:
            stateMessage = "Media is stopped";
            // Additional logic for when media is stopped
            break;
    }
    updateStatusBar();
}

void MainWindow::MediaStatus(QMediaPlayer::MediaStatus status)
{
    switch (status) {
        case QMediaPlayer::NoMedia:
            statusMessage = "No media loaded.";
            break;
        case QMediaPlayer::LoadingMedia:
            statusMessage = "Loading media.";
            break;
        case QMediaPlayer::LoadedMedia:
            statusMessage = "Media loaded.";
            break;
        case QMediaPlayer::StalledMedia:
            statusMessage = "Media playback stalled.";
            break;
        case QMediaPlayer::BufferingMedia:
            statusMessage = "Buffering media.";
            break;
        case QMediaPlayer::BufferedMedia:
            statusMessage = "Media buffered.";
            break;
        case QMediaPlayer::EndOfMedia:
            statusMessage = "End of media.";
            break;
        case QMediaPlayer::InvalidMedia:
            statusMessage = "Invalid media.";
            break;
        default:
            statusMessage = "";
            break;
    }
    updateStatusBar();
}
