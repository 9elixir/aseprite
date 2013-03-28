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

#ifndef RASTER_PALETTE_H_INCLUDED
#define RASTER_PALETTE_H_INCLUDED

#include "raster/frame_number.h"
#include "raster/gfxobj.h"

#include <allegro/color.h>
#include <vector>

class SortPalette
{
public:
  enum Channel {
    RGB_Red,
    RGB_Green,
    RGB_Blue,
    HSV_Hue,
    HSV_Saturation,
    HSV_Value,
    HSL_Lightness,
    YUV_Luma,
  };

  SortPalette(Channel channel, bool ascending);
  ~SortPalette();

  void addChain(SortPalette* chain);

  bool operator()(uint32_t c1, uint32_t c2);

private:
  Channel m_channel;
  bool m_ascending;
  SortPalette* m_chain;
};

class Palette : public GfxObj
{
public:
  enum { MaxColors = 256 };

  Palette(FrameNumber frame, int ncolors);
  Palette(const Palette& palette);
  ~Palette();

  static Palette* createGrayscale();

  int size() const { return m_colors.size(); }
  void resize(int ncolors);

  int getModifications() const { return m_modifications; }

  FrameNumber getFrame() const { return m_frame; }
  void setFrame(FrameNumber frame);

  uint32_t getEntry(int i) const {
    ASSERT(i >= 0 && i < size());
    return m_colors[i];
  }

  void setEntry(int i, uint32_t color);

  void copyColorsTo(Palette* dst) const;

  int countDiff(const Palette* other, int* from, int* to) const;

  // Returns true if the palette is completelly black.
  bool isBlack() const;
  void makeBlack();

  void makeHorzRamp(int from, int to);
  void makeVertRamp(int from, int to, int columns);
  void makeRectRamp(int from, int to, int columns);
  void sort(int from, int to, SortPalette* sort_palette, std::vector<int>& mapping);

  void toAllegro(RGB* rgb) const;
  void fromAllegro(const RGB* rgb);

  static Palette* load(const char *filename);
  bool save(const char *filename) const;

  int findBestfit(int r, int g, int b) const;

private:
  FrameNumber m_frame;
  std::vector<uint32_t> m_colors;
  int m_modifications;
};

#endif
