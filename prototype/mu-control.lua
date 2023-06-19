require "defs"
require "mu"

arsGen = mu.arsGen

mapper = mu.can.mapper
inp = mu.can.input


function b2n(b) return b and 1 or 0 end     -- bool to num
function n2b(n) return n ~= 0 end           -- num to bool


function setup()
    -- Конфигурирование маппера CAN сообщений
    mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}     -- РЦ 1
    mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}     -- РЦ 2

    print("setup done")
end



function loop()
    print("tick")

    -- Управление кодированием первого КТРЦ
    arsGen[1].gen1.f75 = inp[1]
    arsGen[1].gen2.f125 = not n2b(inp[2])

    -- Текущее время в миллисекундах (время с момента запуска)
    time = interface.time()
end