/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CalculationValue_h
#define CalculationValue_h

#include "sky/engine/platform/Length.h"
#include "sky/engine/platform/LengthFunctions.h"
#include "sky/engine/wtf/OwnPtr.h"
#include "sky/engine/wtf/PassOwnPtr.h"
#include "sky/engine/wtf/RefCounted.h"

namespace blink {

class PLATFORM_EXPORT CalculationValue : public RefCounted<CalculationValue> {
public:
    static PassRefPtr<CalculationValue> create(PixelsAndPercent value, ValueRange range)
    {
        return adoptRef(new CalculationValue(value, range));
    }

    float evaluate(float maxValue) const { return pixels() + percent() / 100 * maxValue; }
    bool operator==(const CalculationValue& o) const { return pixels() == o.pixels() && percent() == o.percent(); }
    bool isNonNegative() const { return m_isNonNegative; }
    float pixels() const { return m_value.pixels; }
    float percent() const { return m_value.percent; }
    PixelsAndPercent pixelsAndPercent() const { return m_value; }

private:
    CalculationValue(PixelsAndPercent value, ValueRange range)
        : m_value(value)
        , m_isNonNegative(range == ValueRangeNonNegative)
    {
    }

    PixelsAndPercent m_value;
    bool m_isNonNegative;
};

} // namespace blink

#endif // CalculationValue_h
