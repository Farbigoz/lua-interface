require "defs"
require "interface"

trc3Gen = interface.ktrc.trc3Gen
trc3Rec = interface.ktrc.trc3Rec
arsGen = interface.ktrc.arsGen

mapper = interface.can.mapper
inp = interface.can.input

function b2n(b) return b and 1 or 0 end     -- bool to num
function n2b(n) return n ~= 0 end           -- num to bool


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
    mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}     -- РЦ 1
    mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}     -- РЦ 2

    print("setup done")
end

x = 0

function loop()
    print("tick")

    -- Управление генератором АРС
    arsGen[1].f75 = inp[1]
    arsGen[1].f125 = not n2b(inp[2])
    arsGen[2].f175 = x & 1

    x = x + 1

    -- Текущее время в миллисекундах (время с момента запуска)
    time = interface.time()

    -- print(inp[1])
    -- print(inp[2])
end