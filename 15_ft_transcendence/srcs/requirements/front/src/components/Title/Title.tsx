import React from "react";
import SolidFrame from '../SolidFrame/SolidFrame'
import "./Title.scss"

type TitleProps = {
	frameClass?: string;
	txtClass?: string;
	txt1?: string;
	txt2?: string;
};

const Title: React.FC<TitleProps> = ({
	frameClass = 'title-frame',
	txtClass = 'text-title',
	txt1,
	txt2,
	}) => {
		return (
			<SolidFrame
				frameClass={frameClass}
				txtClass={txtClass}
				txt1={txt1}
				txt2={txt2}
			/>
	);
};

export default Title;
