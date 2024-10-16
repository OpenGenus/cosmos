function getLeapYears(start, end) {
    var startYear = Math.ceil(start / 4) * 4;
    var endYear = Math.floor(end / 4) * 4;
    var leapYears = [];

    if (isNaN(startYear) || isNaN(endYear)) return ['Invalid input'];

    while (startYear <= endYear) {
      if ( startYear % 100 || !(startYear % 400)) {
        leapYears.push(startYear);
      }
      startYear += 4;
    }
    return leapYears.length? leapYears : ['None']; 
}
