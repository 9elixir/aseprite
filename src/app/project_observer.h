/* ASEPRITE
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_PROJECT_OBSERVER_H_INCLUDED
#define APP_PROJECT_OBSERVER_H_INCLUDED

#include "app/project_event.h"

namespace app {

  class ProjectObserver {
  public:
    virtual ~ProjectObserver() { }
    virtual void dispose() = 0;
    virtual void onAddDocument(ProjectEvent& ev) = 0;
    virtual void onRemoveDocument(ProjectEvent& ev) = 0;
  };

} // namespace app

#endif
