-- Импорт библиотек
require "interface"
require "def"

-- Получение интерфейсов
trc3  = interface.trc3Rec   -- Приёмник ТРЦ3

inp   = interface.inputs    -- Входы (битовые, числовые)

-- Функция инициализации и конфигурации (Вызывается автоматически)
function setup()
    -- Конфигурация 1 приёмника ТРЦ3
    trc3[1].level = 30              -- Уровень (мВ)
    trc3[1].freq  = def.F_565_HZ    -- Несущая (Гц)
    trc3[1].mod   = def.F_8_HZ      -- Модуляция (Гц)

    -- Конфигурация 2 приёмника ТРЦ3
    trc3[2].level = 34              -- Уровень (мВ)
    trc3[2].freq  = def.F_780_HZ    -- Несущая (Гц)
    trc3[2].mod   = def.F_12_HZ     -- Модуляция (Гц)
end

-- Функция обработки логики (Вызывается автоматически)
function loop()
    rc1 = trc3[1].rc
    rc2 = trc3[2].rc
    ...
    model(rc1, rc2)
    ...
end


function model()
    ...
end
