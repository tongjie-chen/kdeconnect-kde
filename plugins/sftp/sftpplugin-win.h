/**
 * SPDX-FileCopyrightText: 2019 Piyush Aggarwal <piyushaggarwal002@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
 */

#pragma once

#include <core/device.h>
#include <core/kdeconnectplugin.h>

#define PACKET_TYPE_SFTP_REQUEST QStringLiteral("kdeconnect.sftp.request")

static const QSet<QString> expectedFields = QSet<QString>()
    << QStringLiteral("ip") << QStringLiteral("port") << QStringLiteral("user") << QStringLiteral("password") << QStringLiteral("path");
;
class SftpPlugin : public KdeConnectPlugin
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdeconnect.device.sftp")

public:
    explicit SftpPlugin(QObject *parent, const QVariantList &args);

    void receivePacket(const NetworkPacket &np) override;
    QString dbusPath() const override
    {
        return QStringLiteral("/modules/kdeconnect/devices/") + deviceId + QStringLiteral("/sftp");
    }

public Q_SLOTS:
    Q_SCRIPTABLE bool startBrowsing();

private:
    QString deviceId; // Storing it to avoid accessing device() from the destructor which could cause a crash
};
