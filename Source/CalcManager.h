/// @author M. A. Serebrennikov
#pragma once

#include "CalcBlock.h"
#include "CalcEntity.h"
#include "Command.h"
#include "TypeHash.h"

#include <QtGlobal>
#include <unordered_map>
#include <utility>

namespace sp {

#define CalcI Calc::instance()

/***************************************************************************//**
 * @brief CalcManager управляет цепочкой расчётов.
 ******************************************************************************/
class CalcManager
{
    public:
        CalcManager() = default;

        //----------------------------------------------------------------------
        // TYPES
        //----------------------------------------------------------------------
        /** Конвеер расчётов. */
        using Pipeline = std::vector<CalcBlockUPtr>;

        //----------------------------------------------------------------------
        // SPECIAL
        //----------------------------------------------------------------------
        void setUndoStack();

        /** Регистрирует конвеер расчётов для заданного типа сущности. */
        void registerCalc(const std::type_info * entityType, Pipeline &&);

        /** Запускает расчёт для сущностей. */
        void calc(const std::vector<CalcEntityPtr> & entities);

    private:
        Q_DISABLE_COPY_MOVE(CalcManager);

        using PipelineHash = std::unordered_map<
                                    const Pipeline *,
                                    std::vector<CalcEntityPtr>>;

        PipelineHash distribute(const std::vector<CalcEntityPtr> & entities);

    private:
        TypeHash<Pipeline> _pipelines; ///< Конвеер расчётов для каджого типа сущностей
};

} // namespace sp
