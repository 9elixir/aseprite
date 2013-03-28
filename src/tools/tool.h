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

#ifndef TOOLS_TOOL_H_INCLUDED
#define TOOLS_TOOL_H_INCLUDED

#include <string>

#include "tools/fill.h"
#include "tools/trace_policy.h"

namespace tools {

class Controller;
class Ink;
class Intertwine;
class PointShape;
class ToolGroup;

// A drawing tool
class Tool
{
public:

  Tool(ToolGroup* group,
       const std::string& id,
       const std::string& text,
       const std::string& tips,
       int default_pen_size)
    : m_group(group)
    , m_id(id)
    , m_text(text)
    , m_tips(tips)
    , m_default_pen_size(default_pen_size)
  { }

  virtual ~Tool()
  { }

  const ToolGroup* getGroup() const { return m_group; }
  const std::string& getId() const { return m_id; }
  const std::string& getText() const { return m_text; }
  const std::string& getTips() const { return m_tips; }
  int getDefaultPenSize() const { return m_default_pen_size; }

  Fill getFill(int button) { return m_button[button].m_fill; }
  Ink* getInk(int button) { return m_button[button].m_ink; }
  Controller* getController(int button) { return m_button[button].m_controller; }
  PointShape* getPointShape(int button) { return m_button[button].m_point_shape; }
  Intertwine* getIntertwine(int button) { return m_button[button].m_intertwine; }
  TracePolicy getTracePolicy(int button) { return m_button[button].m_trace_policy; }

  void setFill(int button, Fill fill) { m_button[button].m_fill = fill; }
  void setInk(int button, Ink* ink) { m_button[button].m_ink = ink; }
  void setController(int button, Controller* controller) { m_button[button].m_controller = controller; }
  void setPointShape(int button, PointShape* point_shape) { m_button[button].m_point_shape = point_shape; }
  void setIntertwine(int button, Intertwine* intertwine) { m_button[button].m_intertwine = intertwine; }
  void setTracePolicy(int button, TracePolicy trace_policy) { m_button[button].m_trace_policy = trace_policy; }

private:
  ToolGroup* m_group;
  std::string m_id;
  std::string m_text;
  std::string m_tips;
  int m_default_pen_size;

  struct {
    Fill m_fill;
    Ink* m_ink;
    Controller* m_controller;
    PointShape* m_point_shape;
    Intertwine* m_intertwine;
    TracePolicy m_trace_policy;
  } m_button[2]; // Two buttons: [0] left and [1] right

};

} // namespace tools

#endif  // TOOLS_TOOL_H_INCLUDED
