#include "appdata.h"

#include <QDir>
#include <QStandardPaths>

QString AppData::GetAppDataDirectory()
{
    QString gamepath = QStandardPaths::locate(QStandardPaths::AppDataLocation, "Terraria", QStandardPaths::LocateDirectory);
	if (gamepath.isEmpty()) {
		gamepath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
		if (gamepath.isEmpty()) {
			return {};
		}
		QDir savedir(gamepath);
		if (!savedir.cd("My Games") || !savedir.cd("Terraria")) {
			return {};
		}
		gamepath = savedir.absolutePath();
	}
	return QDir::toNativeSeparators(gamepath);
}

QString AppData::GetModDirectory()
{
	QString gamepath = GetAppDataDirectory();
	if (gamepath.isEmpty()) {
		return {};
	}
    QDir savedir(gamepath);
	if (!savedir.cd("ModLoader") || !savedir.cd("Mods")) {
		return {};
	}
    return QDir::toNativeSeparators(savedir.absolutePath());
}

QStringList AppData::GetModList()
{
	QString modpath = GetModDirectory();
	if (modpath.isEmpty()) {
		return {};
	}
	QDir dir(modpath);
	QStringList entries = dir.entryList({ "*.tmod" });
	return entries;
}
