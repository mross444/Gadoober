-- Set Maestro integration settings to sb1 site
UPDATE RelyingParty
SET Realm = 'https://sb1.geolearning.com/geonext/matctest', Url = 'https://sb1.geolearning.com/geonext/matctest/', LogOffUrl = 'https://sb1.geolearning.com/geonext/matctest/logout.geo', ServiceUrl = 'https://sb1.geolearning.com/services/', ChangePasswordUrl = 'https://sb1.geolearning.com/geonext/NotYetSupported', ForgotPasswordUrl = 'https://sb1.geolearning.com/geonext/forgetpass.geo'
WHERE RPKey = 'MaestroLM'

/*Revert
UPDATE RelyingParty
SET Realm = 'https://prodsup.geolearning.com/geonext/matceds', Url = 'https://prodsup.geolearning.com/geonext/matceds/', LogOffUrl = 'https://prodsup.geolearning.com/geonext/matceds/logout.geo', ServiceUrl = 'https://prodsup.geolearning.com/services/', ChangePasswordUrl = 'https://prodsup.geolearning.com/geonext/NotYetSupported', ForgotPasswordUrl = 'https://prodsup.geolearning.com/geonext/forgetpass.geo'
WHERE RPKey = 'MaestroLM'
*/




-- Set Maestro integration settings to sb1 site
UPDATE RelyingParty
SET Realm = 'https://sb1.geolearning.com/geonext/moraineparktest', Url = 'https://sb1.geolearning.com/geonext/moraineparktest/', LogOffUrl = 'https://sb1.geolearning.com/geonext/moraineparktest/logout.geo', ServiceUrl = 'https://sb1.geolearning.com/services/', ChangePasswordUrl = 'https://sb1.geolearning.com/geonext/NotYetSupported', ForgotPasswordUrl = 'https://sb1.geolearning.com/geonext/forgetpass.geo'
WHERE RPKey = 'MaestroLM'

/*Revert
UPDATE RelyingParty
SET Realm = 'https://prodsup.geolearning.com/geonext/morainepark', Url = 'https://prodsup.geolearning.com/geonext/morainepark/', LogOffUrl = 'https://prodsup.geolearning.com/geonext/morainepark/logout.geo', ServiceUrl = 'https://prodsup.geolearning.com/services/', ChangePasswordUrl = 'https://prodsup.geolearning.com/geonext/NotYetSupported', ForgotPasswordUrl = 'https://prodsup.geolearning.com/geonext/forgetpass.geo'
WHERE RPKey = 'MaestroLM'
*/