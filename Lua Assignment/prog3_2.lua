function Tokenize(str) --tokenize infix to postfix and makes table within table to see if value is a digit 
	local stackstr = {}, i
	for i in string.gmatch(str, "%S+")
	do
		if string.match(i, "%d+")
		then
			table.insert(stackstr, {"digit", i})
		else
			table.insert(stackstr, {"operator", i})
		end
		
	end
	return stackstr
end

function highPrecedence(a, b) --compares operators to see if a >= b, returns false if not
	if (a == '*' or a == '/' or a == '+' or a == '-') and (b == '+' or b == '-')
	then
		return true
	end
	if (a == '*' or a == '/') and (b == '*' or b == '/')
	then
		return true
	end
	return false
end

function InfixToPostfix(str) --tokenizes input, converts infix string to postfix, and returns that string
	local operators = {} 
	local poststack = {}
	local stackstr = ''
	local tokens = Tokenize(str)
	for i = 1, #tokens
	do
		local token = tokens[i]
		if token[1] == "digit"
		then
			table.insert(poststack, token[2])
		else
			while #operators > 0 and highPrecedence(operators[#operators], token[2]) 
			do
				table.insert(poststack, (table.remove(operators)))
			end
			table.insert(operators, token[2])
		end
	end
	while #operators > 0
	do
		table.insert(poststack, (table.remove(operators)))
	end
	for k, v in pairs(poststack) --puts spaces in between chars 
        do
                stackstr = stackstr .. v
                if k < #poststack
                then
                        stackstr  = stackstr .. ' '
                end
        end
	return stackstr 
end
	
function evaluate(str) --evaluates postfix string and returns the popped off number in stack
	local PostString = InfixToPostfix(str) 
	print(PostString)
	local poststack = {}
	local result = {}
	local spaceDelim = string.gsub(PostString, " ","")
	for i = 1, #spaceDelim --puts postfix string into table
	do
    		poststack[i] = spaceDelim:sub(i, i)
	end	
	for i = 1, #poststack
	do
		local item = poststack[i]
		if string.match(item, "%d+")
		then 
			table.insert(result, tonumber(item))
		else
			local num1 = table.remove(result)
			local num2 = table.remove(result)
			local value
			if item == '*' then value = num2 * num1 end
	        	if item == '/' then value = num2 / num1 end
			if item == '+' then value = num2 + num1 end
			if item == '-' then value = num2 - num1 end
			table.insert(result, value)
		end
	end
	return table.remove(result)
end

local str = io.stdin:read()
print(string.format("%d", evaluate(str)))