
        const tryRequire = (path) => {
        	try {
        	const image = require(`${path}`);
        	return image
        	} catch (err) {
        	return false
        	}
        };

        export default {
        
	questionMark: require('./questionMark.png'),
	SideButton_Menu: tryRequire('./SideButton_Menu.png') || require('./questionMark.png'),
	Separator_separator: tryRequire('./Separator_separator.png') || require('./questionMark.png'),
	Profil_avatar: tryRequire('./Profil_avatar.png') || require('./questionMark.png'),
	Profil_upload: tryRequire('./Profil_upload.png') || require('./questionMark.png'),
	Sidebar_TheGreatPongShow: tryRequire('./Sidebar_TheGreatPongShow.png') || require('./questionMark.png'),
	Login_TheGreatPongShow: tryRequire('./Login_TheGreatPongShow.png') || require('./questionMark.png'),
	Chat_SendButton: tryRequire('./Chat_SendButton.png') || require('./questionMark.png'),
}