-- Импорт библиотек
require "interface"
require "def"

-- Получение интерфейсов
alsn  = interface.alsnGen   -- Генератор АЛСН
alsen = interface.alsenGen  -- Генератор АЛС-ЕН
krl   = interface.krlGen    -- Генератор КРЛ

inp   = interface.inputs    -- Входы (битовые, числовые)

-- Функция инициализации и конфигурации (Вызывается автоматически)
function setup()
    -- Конфигурация генератора КРЛ
    krl.level     = 100             -- Уровень (В)
    krl.code      = def.KRL_CODE_C2 -- Кодовая комбинация (индекс)
    krl.freq      = def.F_675_HZ    -- Несущая (Гц)

    -- Конфигурация генератора АЛСН
    alsn.level    = 60              -- Уровень (В)
    alsn.kpt      = def.KPT_5       -- КПТ
    alsn.freq     = def.F_25_HZ     -- Несущая (Гц)

    -- Конфигурация генератора АЛС-ЕН
    alsen.level   = 70              -- Уровень (В)
end

-- Функция обработки логики (Вызывается автоматически)
function loop()
    alsn.none        = inp[2] | inp[3] | inp[4] | inp[5]    -- Нет кода
    alsn.green       = inp[1] | (~inp[6])                   -- Код З
    alsn.red_yellow  = inp[9]                               -- Код КЖ
    alsn.yellow      = inp[7] | inp[8]                      -- Код Ж

    -- code:6,syncGroup:1
    alsen.c6.sg1     = ...
end
