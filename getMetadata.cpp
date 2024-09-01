void MainWindow::GetMetadata(const char* mediaFile) {

    AVFormatContext* fmt_ctx = nullptr;
    if (avformat_open_input(&fmt_ctx, mediaFile, nullptr, nullptr) < 0) {
        qDebug() << "Could not open source: " << mediaFile;
        return;
    }

    // Print detailed information about the format
    av_dump_format(fmt_ctx, 0, mediaFile, 0);

    // Retrieve metadata if available
    AVDictionary* metadata = fmt_ctx->metadata;
    if (metadata) {
        AVDictionaryEntry* tag = nullptr;
        while ((tag = av_dict_get(metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
            std::string key = tag->key;
            if (key == "title") {
                std::string title = tag->value;
                qDebug() << "Title: " << title;
                array["Title"] = QString::fromStdString(title);
            }
            if (key == "artist") {
                std::string artist = tag->value;
                qDebug() << "Artist: " << artist;
                array["Artist"] = QString::fromStdString(artist);
            }
            //std::cout << tag->key << ": " << tag->value << std::endl;
        }
    } else {
        qDebug() << "No metadata available.";
    }

    avformat_close_input(&fmt_ctx);
}
