std::string readLine(std::ifstream& file) {
    std::string line;
    std::getline(file, line);
    return line;
}

bool exists(const std::string& path) {
    return std::filesystem::exists(path);
}

void MainWindow::populateFileList() {
    std::ifstream file("filelist.txt");

    if (!file.is_open()) {
        qDebug() << "File opening failed";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && exists(line)) {
            GetMetadata(line.c_str());

            array["FilePath"] = QString::fromStdString(line);
            QString prettyName = QString("%1 - %2").arg(array["Title"], array["Artist"]);
            // Add to vector map
            metadataMap.push_back(array);

            ui->fileList->addItem(prettyName);
        } else {
            qDebug() << "File doesn't exist: " << line;
        }
    }
}

void MainWindow::Selected (QListWidgetItem *item) {
    if (item) {
        int index = ui->fileList->row(item);
        QString title = metadataMap[index]["Title"];
        QString artist = metadataMap[index]["Artist"];
        QString filePath = metadataMap[index]["FilePath"];
        player->setSource(QUrl::fromLocalFile(filePath));
        QString outputText = QString("%1 - %2").arg(title).arg(artist);
        qDebug() << "Selected item metadata: " << " (File: " << filePath << ")";
        ui->rawText->append(outputText);
    }

    // Use the file path to open or play the file
}
