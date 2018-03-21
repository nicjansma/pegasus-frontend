// Pegasus Frontend
// Copyright (C) 2017  Mátyás Mustoha
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include "PegasusCollections.h"
#include "PegasusMetadata.h"
#include "providers/Provider.h"


namespace providers {
namespace pegasus {

class PegasusProvider : public Provider {
    Q_OBJECT

public:
    explicit PegasusProvider(QObject* parent = nullptr);

    void find(QHash<QString, Types::Game*>&,
              QHash<QString, Types::Collection*>&) final;
    void enhance(const QHash<QString, Types::Game*>&,
                 const QHash<QString, Types::Collection*>&) final;

    void find_in_dirs(const QStringList&,
                      QHash<QString, Types::Game*>&,
                      QHash<QString, Types::Collection*>&) const;
    void enhance_in_dirs(const QStringList&,
                         const QHash<QString, Types::Game*>&,
                         const QHash<QString, Types::Collection*>&) const;

private:
    const QStringList m_game_dirs;
    const PegasusCollections collection_finder;
    const PegasusMetadata metadata_finder;
};

} // namespace pegasus
} // namespace providers