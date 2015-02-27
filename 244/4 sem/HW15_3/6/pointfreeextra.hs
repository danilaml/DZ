{--
func f g l = filter f (map g l)

func f g l = filter (f.g) l

func f g = filter (f.g) == filter ((.) f g)
--}

func = (filter .) . (.)