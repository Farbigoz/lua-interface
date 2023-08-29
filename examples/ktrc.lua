require "defs"
require "interface"

-- Присвоение интерфейсов переменным (чтобы не писать много лишнего кода)
trc3Gen = interface.ktrc.trc3Gen    -- Интерфейс генератора ТРЦ3
trc3Rec = interface.ktrc.trc3Rec    -- Интерфейс приёмника ТРЦ3
arsGen = interface.ktrc.arsGen      -- Интерфейс генератора АРС

mapper = interface.can.mapper       -- Интерфейс CAN маппера
inp = interface.can.input           -- Интерфейс входов CAN маппера


function b2n(b) return b and 1 or 0 end     -- bool to num
function n2b(n) return n ~= 0 end           -- num to bool


-- Функция инициализации (Вызывается 1 раз)
function setup()
    -- Конфигурирование 1 приёмника ТРЦ3
    trc3Rec[1].level = 29
    trc3Rec[1].carrier = defs.F_720_HZ
    trc3Rec[1].mod = defs.F_8_HZ

    -- Конфигурирование 2 приёмника ТРЦ3
    trc3Rec[2].level = 31
    trc3Rec[2].carrier = defs.F_480_HZ
    trc3Rec[2].mod = defs.F_12_HZ

    -- Конфигурирование генератора ТРЦ3
    trc3Gen.level = 99
    trc3Gen.carrier = defs.F_565_HZ
    trc3Gen.mod = defs.F_8_HZ

    -- Конфигурирование генератора АРС
    arsGen.level.f75 = 90
    arsGen.level.f125 = 95
    arsGen.level.f175 = 100
    arsGen.level.f225 = 105
    arsGen.level.f275 = 110
    arsGen.level.f325 = 115
    arsGen.level.f275_ao = 120

    -- Конфигурирование маппера CAN сообщений
    -- Пример:
    --    Айди CAN сообщения КТРЦ под номером 10 = 0x12345678
    --    Состояние 1 РЦ занимает 2 бита, которые находятся в позиции 32
    mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}     -- РЦ 1
    --    Состояние 2 РЦ занимает 2 бита, которые находятся в позиции 34
    mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}     -- РЦ 2
    --    d - Значение по-умолчанию, которое будет установлено, если от КТРЦ не поступало сообщений в течении "timeout" мс
    --    inp - Номер входа, в который будет записано значение (Значение будет записано в interface.can.input[inp])
end


-- Функция обработки (Вызывается циклически)
function loop()
    -- Управление генератором АРС
    arsGen[1].f75 = inp[1]
    arsGen[1].f125 = not n2b(inp[2])
end