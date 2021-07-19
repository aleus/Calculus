#pragma once

#include "UndoStack.h"

namespace sp {

template<class T>
void UndoStack::pushBack(T && command)
{
    // Debug!!! Добавить обработку.
    _stack.push_back(std::forward<T>(command));

    emit canUndoChanged();
    emit canRedoChanged();
}

} // namespace sp
