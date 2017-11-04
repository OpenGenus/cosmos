function trueFalse = isPangram(string)
% Part of Cosmos by OpenGenus Foundation

trueFalse= isempty(find(histc(lower(string),(97:122))==0,1));
end
