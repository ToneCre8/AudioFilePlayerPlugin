/*
    Copyright (C) 2018 Jonathon Racz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "JuceHeader.h"
#include "AudioFileMiniMapWaveform.h"
#include "AudioFileMiniMapHighlight.h"

class AudioFileMiniMap  : public Component
{
public:
    AudioFileMiniMap (AudioFormatManager& formatManagerToUse,
        AudioThumbnailCache& cacheToUse, Value windowLeft, Value windowRight,
        Value lengthSeconds, Value filename);
    ~AudioFileMiniMap();

private:
    AudioFileMiniMapWaveform waveform;
    AudioFileMiniMapHighlight highlight;

    Value windowLeft;
    Value windowRight;
    Value lengthSeconds;
    Point<int> lastMouseDragOffset;

    double getSecondsPerPixel() const;
    double moveWindowLeftEdge (double numSeconds);
    double moveWindowRightEdge (double numSeconds);

    void resized() override;
    void mouseDown (const MouseEvent& event) override;
    void mouseUp (const MouseEvent& event) override;
    void mouseDrag (const MouseEvent& event) override;
};
