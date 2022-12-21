/// @author M. A. Serebrennikov
#pragma once

#include "CalcForward.h"
#include "TypeHash.h"

#include <QtGlobal>
#include <unordered_map>
#include <utility>

namespace sp {

/** Короткое обращение к синглетону Calc. */
#define CalcI Calc::instance()

/***************************************************************************//**
 * @brief Класс Calc позволяет проводить сложные расчёты над массивом
 * сущностей CalcEntity.
 *
 * @details Расчёты для сущностей проводятся через CalcPipeline - последовательно
 * выполняемые расчётные блоки CalcBlock. Программист должен расположить элементы
 * CalcPipeline в виртуальном методе CaleEneityt::pipeline, согласно зависимости
 * от порядка расчёта.
 *
 * Кроме изначально изменённых сущностей, находятся связанные с ними сущности,
 * которые будут затронуты расчётами. И уже итоговый набор сущностей передаётся
 * на расчёт.
 *
 * В каждый CalcBlock передаётся массив сущностей, но не результат вычислений
 * предыдущего расчётного блока из CalcPipeline. Реализация CalcBlock должна
 * самостоятельно выбирать данные из передаваемых сущностей.
 *
 * @warning Предполагается, что основополагающие параметры не пересекаются
 * с расчётными параметрами. В этом случае гарантируется, что не будет
 * рекурсивной зависимости при поиске связанных сущнсотей.
 ******************************************************************************/
class Calc
{
    public:
        static Calc & instance();

        //----------------------------------------------------------------------
        // SPECIAL
        //----------------------------------------------------------------------
        /**
         * Запускает ковеер расчёта для сущностей. Если расчёты завершены без
         * ошибок, то возвращает true.
         */
        bool calc(const std::vector<CalcEntityPtr> & entities);

    private:
        Calc() = default;
        Q_DISABLE_COPY_MOVE(Calc);

        using PipelineHash = std::unordered_map<
                                    const CalcPipeline *,
                                    std::vector<CalcEntityPtr>>;

        /** Распределяет сущности для расщёта между соотвествующими pipeline. */
        PipelineHash distribute(const std::vector<CalcEntityPtr> & entities);

        /** Регистрирует pipeline для сущности. */
        void regPipeline(const CalcEntityPtr & entity);

        /** Регистрирует цепочку расчётов для заданного типа сущности. */
        void regPipeline(const std::type_info * entityType, CalcPipeline && pipeline);

    private:
        TypeHash<CalcPipeline> _pipelines; ///< Конвеер расчётов для каджого типа сущностей
};

} // namespace sp
