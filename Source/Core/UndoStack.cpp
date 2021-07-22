#include "UndoStack.h"

namespace sp {

UndoStack & UndoStack::instance()
{
    static UndoStack result;
    return result;
}

//------------------------------------------------------------------------------
void UndoStack::add(CommandUPtr && command)
{
    if (command->redo()) {
        ++_index;
        _stack.resize(_index + 1);
        _stack[_index] = std::move(command);

        emit canUndoChanged();
        emit canRedoChanged();
    } else {
        command->undo();
    }
}

//------------------------------------------------------------------------------
bool UndoStack::canUndo()
{
    return _index > -1;
}

//------------------------------------------------------------------------------
bool UndoStack::canRedo()
{
    return _index + 1 < static_cast<int>(_stack.size());
}

//------------------------------------------------------------------------------
void UndoStack::undo()
{
    if (canUndo()) {
        _stack[_index]->undo();
        --_index;
        emit canRedoChanged();

        if (_index < 0) {
            emit canUndoChanged();
        }
    }
}

//------------------------------------------------------------------------------
void UndoStack::redo()
{
    if (canRedo()) {
        _stack[_index+1]->redo();
        ++_index;
        emit canUndoChanged();

        if (_index+1 >= static_cast<int>(_stack.size())) {
            emit canRedoChanged();
        }
    }
}

//------------------------------------------------------------------------------
void UndoStack::clear()
{
    _stack.clear();
    _index = -1;

    emit canUndoChanged();
    emit canRedoChanged();
}

} // namespace sp
